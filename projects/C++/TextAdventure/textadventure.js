// Interactive Text Adventure (browser version of textAdventure.cpp)
// Renders into #story and follows the same branching and text.

(function () {
  const correctNumber = 7;

  function el(tag, attrs = {}, ...children) {
    const node = document.createElement(tag);
    Object.entries(attrs).forEach(([k, v]) => {
      if (k === 'class') node.className = v;
      else if (k === 'for') node.htmlFor = v;
      else if (k.startsWith('on') && typeof v === 'function') node.addEventListener(k.slice(2), v);
      else node.setAttribute(k, v);
    });
    children.flat().forEach((c) => {
      if (c == null) return;
      node.appendChild(typeof c === 'string' ? document.createTextNode(c) : c);
    });
    return node;
  }

  function p(text) {
    return el('p', { class: 'fade-in' }, text);
  }

  function br() { return el('br'); }

  function button(label, onClick) {
    return el('button', { type: 'button', onclick: onClick }, label);
  }

  function clear(node) { while (node.firstChild) node.removeChild(node.firstChild); }

  function mountInitialForm(container) {
    clear(container);

    const fields = [
      { key: 'colour', label: 'A colour:' },
      { key: 'weather', label: 'An adjective describing the day:' },
      { key: 'animal1', label: 'Your first animal:' },
      { key: 'name1', label: 'Name your first animal:' },
      { key: 'animal2', label: 'Your second animal:' },
      { key: 'name2', label: 'Name your second animal:' },
      { key: 'food', label: 'A type of food:' },
      { key: 'item', label: 'A miscellaneous item:' },
      { key: 'size', label: 'An adjective describing size:' },
      { key: 'greeting', label: 'An action you do to someone:' },
      { key: 'desc', label: 'An adjective describing someone:' },
    ];

    container.append(
      p('Before we begin our story please enter an answer for each of the following things. This will help build your unique story.'),
      p('Throughout the story, you will be asked to make choices which will affect the way the story progresses.')
    );

    const form = el('form', { id: 'adventure-form', class: 'adventure-form' });
    const grid = el('div', { class: 'form-grid' });
    fields.forEach((f) => {
      const id = `fld_${f.key}`;
      const label = el('label', { for: id }, f.label);
      const input = el('input', { id, name: f.key, required: 'required', type: 'text', 'aria-label': f.label });
      const fieldWrap = el('div', { class: 'field' }, label, input);
      grid.append(fieldWrap);
    });

    form.append(grid);

    const submit = el('button', { type: 'submit' }, 'Begin Your Adventure');
    const actions = el('div', { class: 'actions' }, submit);
    form.append(actions);

    form.addEventListener('submit', (e) => {
      e.preventDefault();
      const fd = new FormData(form);
      const data = {};
      fields.forEach((f) => {
        const val = fd.get(f.key);
        data[f.key] = (val == null ? '' : String(val)).trim();
      });
      startStory(container, data);
    });

    container.append(form);
  }

  function addTitle(container, animal1, animal2) {
    container.append(
      p(''),
      p('Your adventure starts below.'),
      p('=========================================='),
      p(`The ${animal1} and the ${animal2}`),
      p('==========================================')
    );
  }

  function finish(container) {
    container.append(
      p('=============================================='),
      p('I hope you enjoyed the story we wrote together.'),
      p('Thank you and goodbye!'),
      br(),
      button('Restart', () => mountInitialForm(container))
    );
  }

  function startStory(container, s) {
    clear(container);

    addTitle(container, s.animal1, s.animal2);

    container.append(
      p(`The day started like every other, ${s.name1} the ${s.animal1} woke up, pulled back their ${s.colour} curtains and looked outside at the ${s.weather} day.`),
      p(`${s.name1} has a dilemma, do they go back to bed or do they go outside?`)
    );

    const controls = el('div', { class: 'controls' });
    controls.append(
      button('Go back to bed', () => chooseBed(container, s)),
      el('span', {}, ' '),
      button('Go outside', () => chooseOutside(container, s))
    );
    container.append(controls);
  }

  function chooseBed(container, s) {
    container.append(
      p(''),
      p(`${s.name1} decided to go back to bed.`),
      p(`While ${s.name1} slept, they had the most unusual dream. They were in a world where everything was made out of ${s.food}.`),
      p(`The first thing ${s.name1} did was take a massive bite out of the ${s.item}.`),
      p(`${s.name1} hears footsteps coming from behind. ${s.name1} turns around and screams as a ${s.size} ${s.animal2} is running towards them trying to escape from the ${s.food} monster!`),
      p('They both hide under a bridge and hear the monster stomp away.'),
      p(`${s.name1} turns to the ${s.animal2} and introduces themself, the ${s.animal2} then introduces themself as ${s.name2}.`),
      p(`Suddenly, ${s.name1} jolts awake and smiles while thinking about their new friend ${s.name2} the ${s.animal2}.`),
      p('The End.')
    );
    finish(container);
  }

  function chooseOutside(container, s) {
    container.append(
      p(''),
      p(`${s.name1} puts on their favourite ${s.colour} coat and visits a nature park.`),
      p(`The nature park is very busy today and ${s.name1} doesn't like crowds so decided to go find a quiet place to read.`),
      p(`${s.name1} sees two possible locations, the treehouse or rent a boat and go on the lake.`)
    );

    const controls = el('div', { class: 'controls' });
    controls.append(
      button('Treehouse', () => chooseTreehouse(container, s)),
      el('span', {}, ' '),
      button('Lake', () => chooseLake(container, s))
    );
    container.append(controls);
  }

  function chooseTreehouse(container, s) {
    container.append(
      p(''),
      p(`${s.name1} starts the climb up the treehouse, upon entering they notice a ${s.size} ${s.animal2} in the corner reading a book.`),
      p(`The ${s.animal2} ${s.greeting} to ${s.name1} and says their name is ${s.name2}.`),
      p(`${s.name2} asks ${s.name1} if they would like to play a game.`)
    );

    const controls = el('div', { class: 'controls' });
    controls.append(
      button('Play the game', () => treehouseGamePrompt(container, s)),
      el('span', {}, ' '),
      button("Don't play", () => treehouseNoGame(container, s))
    );
    container.append(controls);
  }

  function treehouseNoGame(container, s) {
    container.append(
      p(''),
      p(`${s.name2} says "that is alright" and goes back to reading their book.`),
      p(`${s.name1} sits down in the treehouse with ${s.name2} and they both read their books in silence.`),
      p('The End.')
    );
    finish(container);
  }

  function treehouseGamePrompt(container, s) {
    container.append(
      p(''),
      p(`${s.name2} says "I am thinking of a number between 1-10.`),
      p('In order to win the game, you have to guess the correct number. You have 3 guesses.')
    );

    let attemptsLeft = 3;
    const controls = el('div', { class: 'controls' });
    const input = el('input', { type: 'number', min: '1', max: '10', placeholder: 'Enter guess (1-10)' });
    const submit = button('Guess', onGuess);

    controls.append(input, el('span', {}, ' '), submit);
    container.append(controls);

    function onGuess() {
      const guess = Number(input.value);
      if (!Number.isInteger(guess) || guess < 1 || guess > 10) {
        container.append(p('Invalid guess, please enter a number 1-10.'));
        return;
      }
      attemptsLeft--;
      if (guess === correctNumber) {
        container.append(
          p(''),
          p(`Vicory! The correct number was ${correctNumber}.`),
          p('The End.')
        );
        controls.remove();
        finish(container);
        return;
      }
      if (attemptsLeft > 0) {
        container.append(p(`Incorrect guess, ${s.name1} has ${attemptsLeft} guesses left. Try again.`));
        input.value = '';
        input.focus();
      } else {
        container.append(
          p(''),
          p(`${s.name1} has failed the game. ${s.name2} pushes ${s.name1} out of the treehouse.`),
          p('The End.')
        );
        controls.remove();
        finish(container);
      }
    }
  }

  function chooseLake(container, s) {
    container.append(
      p(''),
      p(`${s.name1} walks over to the boat hire outhouse. Inside there is a ${s.desc} sales assistant, who says "Welcome! To hire a boat for 1 hour it is $50".`),
      p('"Do you want to hire one?"')
    );

    const controls = el('div', { class: 'controls' });
    controls.append(
      button('Hire a boat', () => lakeHireYes(container, s)),
      el('span', {}, ' '),
      button("Do not hire", () => lakeHireNo(container, s))
    );
    container.append(controls);
  }

  function lakeHireYes(container, s) {
    container.append(
      p(''),
      p(`${s.name1} hands over the $50 and makes their way to the ${s.colour} boat.`),
      p(`Once ${s.name1} is floating in the middle of the lake, they pull out the book appreciating the silence on the water.`),
      p(`Until they hear a splashing getting closer. ${s.name1} looks left and right, but sees no one. ${s.name1} is starting to get scared, the splashing is getting louder and louder, but still there is noone around.`),
      p(`Suddenly a ${s.size} ${s.animal2} breaks the surface of the water and climbs onto the boat.`),
      p(`The ${s.animal2} quickly looks around and spots ${s.name1} and ${s.greeting} to them.`),
      p(`A wicked smile creeps onto their face as they shout "My name is ${s.name2} and I am commandeering this boat"`),
      p(`${s.name2} throws ${s.name1} overboard and sails away taking ${s.name1}'s book with them.`),
      p('The End.')
    );
    finish(container);
  }

  function lakeHireNo(container, s) {
    container.append(
      p(''),
      p(`${s.name1} decides not to hire the boat, and instead goes home to read their book "${s.name2}'s battle over the ${s.size} ${s.colour} ${s.food} monster" snuggled under a blanket in front of the fire eating ${s.food}.`),
      p('The End.')
    );
    finish(container);
  }

  document.addEventListener('DOMContentLoaded', () => {
    const mount = document.getElementById('story');
    if (!mount) return;
    mountInitialForm(mount);
  });
})();
