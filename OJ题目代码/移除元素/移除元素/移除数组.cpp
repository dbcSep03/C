int removeElement(int* nums, int numsSize, int val) {
	int location = 0;
	for (int site = 0; site < numsSize; site++)
	{

		if (*(nums + site) != val)
		{
			*(nums + location) = *(nums + site);
			location++;
		}
	}
	return location;
}
int main()
{
	return 0;
}