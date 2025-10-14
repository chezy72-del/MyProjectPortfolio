document.addEventListener('DOMContentLoaded', () => {
    // Helper: return array of checked checkbox ids inside a form
    function getCheckedClasses(formId) {
        const checked = Array.from(document.querySelectorAll(`#${formId} input[type="checkbox"]:checked`));
        return checked.map(cb => cb.id);
    }

    // Main filter: show project cards that match selected languages (any) AND selected difficulties (any)
    function filterProjects() {
        const langSelected = getCheckedClasses('form_1'); // e.g. ['lang_python']
        const diffSelected = getCheckedClasses('form_2'); // e.g. ['diff_beginner']

        const projects = document.querySelectorAll('.project_card');

        let visibleCount = 0;
        projects.forEach(project => {
            const matchesLanguage = langSelected.length === 0 || langSelected.some(cls => project.classList.contains(cls));
            const matchesDifficulty = diffSelected.length === 0 || diffSelected.some(cls => project.classList.contains(cls));

            if (matchesLanguage && matchesDifficulty) {
                project.style.display = 'inline-block';
                visibleCount++;
            } else {
                project.style.display = 'none';
            }
        });

        const noResults = document.getElementById('no_results_message');
        if (noResults) {
            noResults.style.display = visibleCount === 0 ? 'block' : 'none';
        }
    }

    // Wire up checkbox change listeners and run initial filter
    const inputs = document.querySelectorAll('#form_1 input[type="checkbox"], #form_2 input[type="checkbox"]');
    inputs.forEach(i => i.addEventListener('change', filterProjects));
    // Expose convenience functions for compatibility if inline handlers remain
    window.filterLanguage = filterProjects;
    window.filterDifficulty = filterProjects;

    filterProjects();
});