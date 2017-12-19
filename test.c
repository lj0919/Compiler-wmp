int main()
{









//	int b = a, a = b; // G | T, allow type since some one would like to do two pass










	//char c, int d; // G, not allowed expr
	
	//int char; // G

//	s s; // L | G, since if someone has support struct	
	






//	int c; // G | T, replication declaration









//	int g = { 1, 2 }; // G | T, not proper initialization , can be tolerate











//	1 = 3; // G | T , since 1 is rvalue, cannot be assigned









//	(g + 1) = ( c - 1); // G | T, rvalue problem
	












//	(a) = (b - a) = (c -a ); // G | T, rvalue









	
//	if(if(a)){} // G
	
//	if(int a = 0){} // G

//	if(0) // G
	
//	a = if(0) 1 else 2; // G

}
