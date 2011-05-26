/** This function will take care of swapping between choices and and story sketches  */
function swap(swid){
  var story_element;
  var choice_element;

  story_element = document.getElementById('story');
  choice_element = document.getElementById('choice');

  // Set the new contents of the divs!
  story_element.innerHTML = storyArray[swid]; 
  choice_element.innerHTML = choiceArray[swid];

}

/** Standard initialization routines */
function init(){
  var title_element = document.getElementById('storytitle');
  // Set the story to the start
  swap(0);
  // Set the title 
  title_element.innerHTML = titleOfStory;
}
