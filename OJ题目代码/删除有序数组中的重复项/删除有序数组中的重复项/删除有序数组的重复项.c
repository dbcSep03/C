int removeDuplicates(int* nums, int numsSize) {
	int site = 0;
	for (int location = 0; location < numsSize; location++)
	{
		if (*(nums + site) != *(nums + location))
		{
			site++;
			*(nums + site) = *(nums + location);
		}
		
	}
	return site + 1;
}
int main()
{
	return 0;
}