// Tic Tac Toe client-side script (moved from inline in ttt.html)
document.addEventListener('DOMContentLoaded', function () {
    const gameRoot = document.getElementById('game');

    const board = Array(9).fill(null); // null, 'X' or 'O'
    let current = 'X';
    let finished = false;

    function createBoard() {
        gameRoot.innerHTML = '';
        const panel = document.createElement('div');
        panel.id = 'ttt-panel';

        const status = document.createElement('div');
        status.id = 'ttt-status';
        status.textContent = 'Current: ' + current;

        const grid = document.createElement('div');
        grid.id = 'ttt-grid';

        for (let i = 0; i < 9; i++) {
            const cell = document.createElement('button');
            cell.className = 'ttt-cell';
            cell.dataset.index = i;
            cell.addEventListener('click', onCellClick);
            grid.appendChild(cell);
        }

        const restart = document.createElement('button');
        restart.className = 'ttt-restart';
        restart.textContent = 'Restart';
        restart.addEventListener('click', reset);

        panel.appendChild(status);
        panel.appendChild(grid);
        panel.appendChild(restart);
        gameRoot.appendChild(panel);

        render();
    }

    function onCellClick(e) {
        if (finished) return;
        const idx = Number(e.currentTarget.dataset.index);
        if (board[idx]) return;
        board[idx] = current;
        if (checkWin(current)) {
            finished = true;
            setStatus(current + ' wins!');
        } else if (board.every(Boolean)) {
            finished = true;
            setStatus('Draw');
        } else {
            current = (current === 'X') ? 'O' : 'X';
            setStatus('Current: ' + current);
        }
        render();
    }

    function setStatus(text) {
        const s = document.getElementById('ttt-status');
        if (s) s.textContent = text;
    }

    function render() {
        const cells = document.querySelectorAll('.ttt-cell');
        cells.forEach(c => {
            const i = Number(c.dataset.index);
            c.textContent = board[i] || '';
            c.disabled = Boolean(board[i]) || finished;
        });
    }

    function checkWin(player) {
        const lines = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],
            [0, 3, 6], [1, 4, 7], [2, 5, 8],
            [0, 4, 8], [2, 4, 6]
        ];
        return lines.some(line => line.every(i => board[i] === player));
    }

    function reset() {
        for (let i = 0; i < 9; i++) board[i] = null;
        current = 'X'; finished = false;
        setStatus('Current: ' + current);
        render();
    }

    // initialize
    createBoard();
});
