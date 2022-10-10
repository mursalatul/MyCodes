ll rev(ll x)
{
	ll a = 0;
	while (x)
	{
		a = (a * 10) + (x % 10);
		x /= 10;
	}
	return a;
}
