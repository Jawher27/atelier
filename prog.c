#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

int main(int argc, char** argv)
{


int quit=0;
if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    {
      printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
      return EXIT_FAILURE;
    }
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
  	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
       	{
  		      printf("audio no can do %s\n",Mix_GetError());
  	    }
      	Mix_Music *music;
        Mix_Music *music1;

  	music =Mix_LoadMUS("PSGSONG.mp3");
    	music1 =Mix_LoadMUS("RMASONG.mp3");
  //	Mix_PlayMusic(music,-1);
    	Mix_VolumeMusic(99);


    SDL_Surface *image,*screen;
    	SDL_Rect offset;
	SDL_Event event;



    screen = SDL_SetVideoMode( 640, 440, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if( screen == NULL )
    {
      printf( "Can't set video mode: %s\n", SDL_GetError( ) );
      return EXIT_FAILURE;
    }
image=IMG_Load("champions.jpg");

if (image==NULL)
    {
    printf("can't image %s\n", SDL_GetError( ));
    return EXIT_FAILURE;
    }

offset.x=0;
offset.y=0;
int i=0;
    while(quit == 0)
{

  SDL_BlitSurface(image,NULL,screen,&offset);
  while(SDL_PollEvent(&event))
		{
			switch(event.type)
      {

  case SDL_QUIT:
        {
         				quit = 1;
				}
				break;


        case SDL_KEYDOWN:
        {
          if(event.key.keysym.sym == SDLK_DOWN)
          {
            Mix_PlayMusic(music1,-1);
          }
            //if ((i%2)==0)
            if(event.key.keysym.sym == SDLK_UP)


        //  else
          {
            Mix_PlayMusic(music,-1);

          }
          //  i++;


    break;
        }




}
}
SDL_Flip(screen);
}
return 0;
}
