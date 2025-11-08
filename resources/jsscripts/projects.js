// Select the first element with class "redline". Using querySelector avoids errors
const img = document.querySelector('.redline');

function enlargeImg() {
    if (!img) return;
    img.style.transform = 'scale(3)';
    img.style.transition = 'transform 0.25s ease';
}

// Function to reset image size
function resetImg() {
    if (!img) return;
    img.style.transform = 'scale(1)';
    img.style.transition = 'transform 0.25s ease';
}