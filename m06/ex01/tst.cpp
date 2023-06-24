int main(void)
{
	int    a = 0;
	double b = a;			/* implicit converstion cast */
	double c = (double)a;	/* explicit conversion */
	double d = a;			/* ok becuase we are going down in in presisious */
	int    e = b;			/* we loose information */
	int	   f = (int)b;		/* still loose information but it's signaled so we know it's ok */	

	// -no-conversion gcc flag to stop implicit conversion when info would be lost

	/* reinterpretation cast */

	float g = 42.042f;

	void *h = &g;			/* implicit reinterprentatino cast */

	// void is a more general pointer type than any other pointer type
	
	void *i = (void *) &g;
}

