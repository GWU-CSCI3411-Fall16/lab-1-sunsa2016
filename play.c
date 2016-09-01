#include <stdio.h>

char* titles = {"Never Give You Up", "Stainway to Heaven"};
char* singers = {"Rick Astley", "Led Zeppelin"};

struct song_t
{
	char* title;
	char* singer;
};

struct node_t
{
	struct song_t* song;
	struct node_t* next;
};

void print_playlist(struct node_t* node)
{
	struct node_t* ptr;
	ptr = node;

	while(ptr != NULL)
	{
		printf("%s by %s\n", ptr -> song -> title, ptr -> song -> singer);
		ptr = ptr -> next;
	}
}
int main(int argc, char* argv[])
{
	struct song_t ricksong, ledsong;
	struct node_t p1_rick, p1_led, p2_rick, p2_led;

	unsigned i;

	ricksong.title = titles[0];
	ricksong.singer = singers[0];	

	ledsong.title = titles[1];
	ledsong.singer = singers[1];
	
	p1_rick.song = &ricksong;
	p1_rick.next = &p1_led;	
	p1_led.song = &ledsong;
	p1_led.next = NULL;

	print_playlist(&p1_rick);
	return 0;
}
