// Select the first .redline image
const img = document.querySelector('.redline');

function enlargeImg() {
    if (!img) return;
    img.classList.add('enlarged');
}

function resetImg() {
    if (!img) return;
    img.classList.remove('enlarged');
}