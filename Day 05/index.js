const board = document.getElementById("board");
const statusText = document.getElementById("status");
const restartBtn = document.getElementById("restartBtn");

const popup = document.getElementById("popup");
const popupText = document.getElementById("popupText");
const popupIcon = document.getElementById("popupIcon");

let currentPlayer = "X";
let gameActive = true;
let gameState = ["", "", "", "", "", "", "", "", ""];

const winConditions = [
    [0,1,2], [3,4,5], [6,7,8], //row
    [0,3,6], [1,4,7], [2,5,8],  //colm
    [0,4,8], [2,4,6] //dgnl
];

function createBoard() {
    board.innerHTML = "";
    gameState.forEach((cell, index) => {
        const cellDiv = document.createElement("div");
        cellDiv.classList.add("cell");
        cellDiv.setAttribute("data-index", index);
        cellDiv.innerText = cell;
        cellDiv.addEventListener("click", handleCellClick);
        board.appendChild(cellDiv);
    });
}

function handleCellClick(event) {
    const index = event.target.getAttribute("data-index");

    if(gameState[index] !== "" || !gameActive) return;

    gameState[index] = currentPlayer;
    event.target.innerText = currentPlayer;
    checkResult();
}

function checkResult() {
    let won = false;

    winConditions.forEach(condition => {
        const [a,b,c] = condition;
        if(gameState[a] && gameState[a] === gameState[b] && gameState[a] === gameState[c]) {
            won = true;
        }
    });

    if(won) {
        gameActive = false;
        showPopup(`${currentPlayer} Wins!`, "win");
        return;
    }

    if(!gameState.includes("")) {
        gameActive = false;
        showPopup("It's Draw!", "draw");
        return;
    }

    currentPlayer = currentPlayer === "X" ? "O" : "X";
    statusText.innerText = `Player ${currentPlayer}'s turn`;
}

function showPopup(text, type) {
    popup.classList.remove("hidden");
    popupText.innerText = text;

    if(type === "win") {
        popupIcon.innerHTML = `<!-- Trophy SVG -->
        <svg viewBox="0 0 24 24"><path d="M6 2h12l-1 7a5 5 0 01-10 0L6 2z"/></svg>`;
    }

    if(type === "draw") {
        popupIcon.innerHTML = `<!-- Handshake SVG -->
        <svg viewBox="0 0 24 24"><path d="M2 12l5 5 5-5-5-5-5 5z"/></svg>`;
    }
}

restartBtn.addEventListener("click", () => {
    currentPlayer = "X";
    gameActive = true;
    gameState = ["","","","","","","","",""];
    statusText.innerText = "New Game!";
    popup.classList.add("hidden");
    createBoard();
});

createBoard();


