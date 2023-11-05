#include <stdio.h>
#include <SFML/Graphics.h>

#define CIRCLE_RADIUS 30
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
	sfVideoMode mode = { SCREEN_WIDTH, SCREEN_HEIGHT, 32 };
	sfRenderWindow* window;
	sfCircleShape* circle;
	sfVector2f circlePos = { SCREEN_WIDTH / 2 - CIRCLE_RADIUS, SCREEN_HEIGHT / 2 - CIRCLE_RADIUS};
	sfEvent event;


	/* Create the main window */
	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	circle = sfCircleShape_create();

	sfCircleShape_setPosition(circle, circlePos);
	sfCircleShape_setRadius(circle, CIRCLE_RADIUS);
	sfCircleShape_setOutlineThickness(circle, 5);
	sfCircleShape_setFillColor(circle, sfWhite);
	sfCircleShape_setOutlineColor(circle, sfBlack);


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
		sfRenderWindow_drawCircleShape(window, circle, NULL);
		sfRenderWindow_display(window);
	}

	sfCircleShape_destroy(circle);
	sfRenderWindow_destroy(window);
	return 0;
}