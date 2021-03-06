#include<stdio.h>
#include<MLV/MLV_all.h>

void affichage(int x, int y)
{

	MLV_draw_text(
		x, y,
		"(%d,%d)",
		MLV_COLOR_MIDNIGHT_BLUE,
		x, y
	);	
	MLV_actualise_window();
}


int main(int argc, char *argv[])
{
  MLV_Image *image;
  int width = 1080;
  int height = 720;
  MLV_create_window("fenetre","icone fenetre",width,height);
  image = MLV_load_image("pirate.jpg");
  MLV_resize_image_with_proportions(image,width,height);
  MLV_draw_image(image,0,0);
  MLV_actualise_window();
 
    int i,j;
   for (i=0;i<width;i=i+60)
    {
    for(j=0;j<height;j=j+60)
      {
      MLV_draw_rectangle(i,j,60,60,MLV_COLOR_YELLOW1);
      }
    }
 
      	int x = 0, y = 0;
	MLV_Event event;
	affichage(x, y);
	do {event = MLV_get_event( 	NULL, NULL, NULL,
			NULL, NULL,
			&x, &y, NULL,
			NULL
		);
		if( event == MLV_MOUSE_BUTTON )
		  {
			affichage(x, y);
		  };
	}while (event != MLV_KEY);
        MLV_wait_seconds(10);
}
