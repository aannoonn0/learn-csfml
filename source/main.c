#include <stdio.h>
#include <math.h>
#include <SFML/Graphics.h>

#define CIRCLE_RADIUS 30
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define SIN_AMPLITUDE 20
#define SIN_PERIOD 10

int main()
{
	double sinpos;
	sfTime t;

	sfVideoMode mode = { SCREEN_WIDTH, SCREEN_HEIGHT, 32 };
	sfEvent event;


	sfRenderWindow* window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	sfCircleShape* circle = sfCircleShape_create();
	sfClock* clock = sfClock_create();


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

		t = sfClock_getElapsedTime(clock);
		double x = sfTime_asSeconds(t);
		sinpos = SIN_AMPLITUDE * sin(x * SIN_PERIOD);
		
		sfVector2f circlePos = { SCREEN_WIDTH / 2 - CIRCLE_RADIUS, (SCREEN_HEIGHT / 2 - CIRCLE_RADIUS) + sinpos };
		sfCircleShape_setPosition(circle, circlePos);
		printf("%f\n", sinpos);


		sfRenderWindow_clear(window, sfWhite);
		sfRenderWindow_drawCircleShape(window, circle, NULL);
		sfRenderWindow_display(window);
	}

	sfCircleShape_destroy(circle);
	sfRenderWindow_destroy(window);
	return 0;
}