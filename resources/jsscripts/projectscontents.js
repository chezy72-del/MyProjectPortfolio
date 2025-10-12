function filterProject() {
    // Get all checkboxes for languages
    const languageCheckboxes = document.querySelectorAll('input[name="language"]');
    // Get all checkboxes for difficulty levels
    const difficultyCheckboxes = document.querySelectorAll('input[name="difficulty"]');
    
    // Create arrays to hold selected languages and difficulties
    const selectedLanguages = Array.from(languageCheckboxes)
        .filter(checkbox => checkbox.checked)
        .map(checkbox => checkbox.id.replace('lang_', ''));
    
    const selectedDifficulties = Array.from(difficultyCheckboxes)
        .filter(checkbox => checkbox.checked)
        .map(checkbox => checkbox.id.replace('diff_', ''));
    
    // Get all project items
    const projects = document.querySelectorAll('.project_item');
    
    projects.forEach(project => {
        const projectLanguages = project.getAttribute('data-languages').split(',');
        const projectDifficulty = project.getAttribute('data-difficulty');
        
        // Check if project matches selected languages
        const matchesLanguage = selectedLanguages.length === 0 || selectedLanguages.some(lang => projectLanguages.includes(lang));
        // Check if project matches selected difficulties
        const matchesDifficulty = selectedDifficulties.length === 0 || selectedDifficulties.includes(projectDifficulty);
        
        // Show or hide project based on filters
        if (matchesLanguage && matchesDifficulty) {
            project.style.display = '';
        } else {
            project.style.display = 'none';
        }
    });
}