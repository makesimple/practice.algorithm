void permutation(string a, int l, int r)  
{
    if (l == r)  
        std::cout<<a<<std::endl;  
    else
    {
        for (int i = l; i <= r; i++)  
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);  
        }
    }
}
