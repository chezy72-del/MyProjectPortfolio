// Redline enlargement logic supporting two patterns:
// 1. Legacy inline handlers: <img class="redline" onclick="enlargeImg(this)" onmouseout="resetImg(this)">
//    - Click adds .enlarged, mouseout removes.
// 2. Auto-bind toggle for images without inline handlers.
//    - Click toggles .enlarged.
// This avoids a double-fire where inline enlarge + auto toggle would immediately cancel.

document.addEventListener('DOMContentLoaded', () => {
    const redlines = document.querySelectorAll('.redline');
    redlines.forEach(img => {
        const hasInline = img.getAttribute('onclick') || img.getAttribute('onmouseout');
        if (hasInline) return; // Respect existing inline behavior.
        img.addEventListener('click', () => {
            img.classList.toggle('enlarged');
        });
    });
});

// Helper functions (global) usable by inline attributes or other scripts.
function enlargeImg(target = '.redline') {
    if (typeof target === 'string') {
        document.querySelectorAll(target).forEach(el => el.classList.add('enlarged'));
    } else if (target instanceof Element) {
        target.classList.add('enlarged');
    }
}

function resetImg(target = '.redline') {
    if (typeof target === 'string') {
        document.querySelectorAll(target).forEach(el => el.classList.remove('enlarged'));
    } else if (target instanceof Element) {
        target.classList.remove('enlarged');
    }
}