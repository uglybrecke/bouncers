# Instructions

In this activity we will be refactoring a demo to use classes and functions. In doing so we will make the code more reusable and set the stage for separating our code into separate files.

YOU MUST BE MAKING FREQUENT COMMITS THROUGHOUT!

## Livecode Steps
1. Fork/clone and ensure that GitHub Actions and are enabled and GitHub pages are set to use GitHub Actions.
1. Make/run the demo and understand what the starter code is doing. Make sure to not just look at the display, but also the debug output.
1. Refactor the average logic into a separate function.
1. Refactor the bouncer adding logic into a separate function.
1. Create a Bouncer class and make a single unmoving bouncer.
1. Temporarily remove the calls to the average and adding functions. 
1. Refactor the updating logic to use the Bouncer class.
1. Refactor the adding function to use Bouncer class and uncomment the call to it.
1. Move the updating logic to a member function.

## Required Homework Steps
1. Refactor the average function to use the Bouncer class. and uncomment the call to it.
1. Add a y_speed and change the update member function to make the Bouncer move in two dimensions.
1. Make the x_speed and y_speed start as random values. I strongly recommend looking at the Butano random examples and [documentation](https://gvaliente.github.io/butano/classbn_1_1random.html)! Hint: you will need to re-use the same bn::random instance repeatedly to get different random values.
    
    If all is working well at this point you should see behavior that looks like this:
    
    ![Sample recording of balls bouncing in random directions](./donuts_pop.gif)
1. Make a new sprite to replace the yellow dot
1. Choose at least one of the extensions (see below section) or come up with one of your own!
1. Make a GIF of your game.
1. Create a nice README that describes your game and includes the GIF and a link to the live GitHub pages version.
1. Submit (see instructions on Canvas).



## Extensions
1. Add a background (NOT just a backdrop color). Consider looking at the Butano background example for how to do this.
1. Make each dot dissapear after a certain amount of time.
1. Make a different dot that always stays at the average position of all the dots. Re-use exisiting functions well!
1. Come up with your own idea!
