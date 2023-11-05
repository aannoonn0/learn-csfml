#include <SFML/Audio.h>
#include <SFML/Graphics.h>


int main()
{
	sfVideoMode mode = { 800, 600, 32 };
	sfRenderWindow* window;
	sfEvent event;


	/* Create the main window */
	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);


	/* Start the game loop */
	while (sfRenderWindow_isOpen(window))
	{

		/* Process events */
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
		}

		sfRenderWindow_clear(window, sfWhite);
		sfRenderWindow_display(window);
	}

	sfRenderWindow_destroy(window);
	return 0;
}