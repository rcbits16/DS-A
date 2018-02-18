#include<stdio.h>
void p();
void g();
void h();
void d();

int bits=0;

int main(void)
{
	p(0);
}

void p()
{
	int pilani;
	printf("bits %dPilani:%u\n",bits,&pilani);
	bits++;
	p();
}

void g(void)
{
	int goa;
	printf("Goa:%u\n",&goa);
	h();
}

void h(void)
{
	int hyderabad;
	printf("Hydra:%u\n",&hyderabad);
	d();
}

void d(void)
{
	int dubai;
	printf("Dubai:%u\n",&dubai);
}
