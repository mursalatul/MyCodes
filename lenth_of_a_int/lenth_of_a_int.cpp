ll len(ll x)
{
	ll l = 0;
	while (x)
	{
		x /= 10;
		l++;
	}
	return l;
}
