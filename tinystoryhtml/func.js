/** This function will take care of swapping between choices and and story sketches  
TODO add a lock 
*/

// This is a global to protect the animation - in other words, while animation is 
// undergoing, don't let the user click on anything else. 
var ANIMATION_LOCK = 0;

/** This is a routine which swaps between story paragraphs. jQuery makes pretty
fade in and out animations. */
function swap(swid){
  if(ANIMATION_LOCK == 0){
    ANIMATION_LOCK = 1; // Animating, lock
    $(document).ready(function(){
      // Fade out, change text, fade in 
      $('#story').fadeOut('slow', function() { 
          $(this).html(storyArray[swid]);
        }).fadeIn('slow');
      $('#choice').fadeOut('slow', function() { 
          $(this).html(choiceArray[swid]);
        }).fadeIn('slow', function(){
          ANIMATION_LOCK = 0; // Animation done, unlock
        });
    });
  }
}

/** Standard initialization routines. This part just initializes the boxes
to the first elements of storyArray and choiceArray (which are assumed to be there
by the person writting the story - ie requirement to set a blob with id 0 for
the first page...) */
function init(){
  // Set the title of story 
  $('#storytitle').html = titleOfStory;
  // Set the initial stuff to show
  $('#story').html(storyArray[0]);
  $('#choice').html(choiceArray[0]);
}

