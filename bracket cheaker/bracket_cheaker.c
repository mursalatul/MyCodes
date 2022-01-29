#include <stdio.h>
#include <string.h>


int ordered_input_arrayeaket(char input_array[])
{
	/*
	algorithm:
	step 1: consider only the brackets in the array.(line: 24, 29, 33, 37)
	step 2: if we found 1st brackets, store that into a store array.(line: 26)
	step 3: if we found 2nd brackets, see if the last input bracket in the store match the 2nd
			bracket or not. if match, replace it by '0'. or return false.(line: 45)
	step 4: after iterate all the brackets in the array see if there any remainding 1st brackets
			in the store. if no then return true, else return false.(line: 68)
	*/
	int  i, j, len = strlen(input_array);
	char store[len], target = '0'; // store: store starting brackets to track its closing brackets

	// iterate 1st to last and calculating brackets. we will consider brackets only in input_array
	for (i = 0; i < len; i ++)
	{
		// if element is starting bracket, store it in order
		if ((input_array[i] == '(') || (input_array[i] == '{') || (input_array[i] == '['))
		{
			store[i] = input_array[i];
		}
		// if element is ending bracket, target it's starting bracket
		else if (input_array[i] == ')')
		{
			target = '(';
		}
		else if (input_array[i] == '}')
		{
			target = '{';
		}
		else if (input_array[i] == ']')
		{
			target = '[';
		}
		else target = '0';

		// start searching when target is active, targer = (/{/[
		// find and remove(replace by '0') target.
		for (j = i - 1; j >= 0, target != '0'; j --)
		{
			// consider brackets in store. escap the '0' and emtry locations('\000')
			if ((store[j] == '(') || (store[j] == '{') || (store[j] == '['))
			{
				// if first bracket match the this bracket is in right order.
				// so remove it(replace by '0') and break
				if (store[j] == target)
				{
					store[j] = '0';
					break; // need to remove 1 target cause 1 ending bracket = 1 starting bracket
				}
				// if target bracket isnt in the store then its mean we have 2nd bracket without
				// it first bracket. so it is not ordered
				else return 0;
				
			}
		}
		// set the value of target '0' after every operation. otherwise target will be keep active after it is first time active.
		// and we dont want it active when its first brackets or other characters.
		target = '0';
	}
	// finding if there is any remining bracket in store. if yes then bracket is not ordered.
	for (i = 0; i < len; i ++)
	{
		if ((store[i] == '(') || (store[i] == '{') || (store[i] == '['))
		{
			return 0;
		}
	}
	// if store is emty thats means all the intered first brackets are replaced by '0' by it's
	// seconds brackets. so its ordered.
	return 1;
}

int main(void)
{
	int len, res;
	char str[1000];
	
	// taking a string. this will take input until its line break
	printf("Input: ");
	scanf("%[^\n]%*c", str);
	
	//calling the function
	res = ordered_input_arrayeaket(str);
	
	if (res)
	{
		printf("Brackets: Ordered\n");
	}
	else
	{
		printf("Brackets: Not Ordered\n");
	}
	
	return 0;
}
