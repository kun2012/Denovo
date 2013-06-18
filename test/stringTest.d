class StringTest
{
	String box="this\b is\n a\f test\t";
	String box2 = "Test a new line \
a escape new line,no error";

	Int input()//get a line of characters
	{
		gets(box);
		return box;
	}
	Bool empty()/*Is data empty? */
	{
		if (box.length()>0) return 0;
		else return 1;
	}
	Int maxlength()
	{
		Int x=box.size();
		x=x*2;
		if (x>=100) return 100;
		if (x!=0) return x/2;
	}
	void main()
	{
		while (maxlength<=0) input();
		return 0;
	}
}
/* infinite error

