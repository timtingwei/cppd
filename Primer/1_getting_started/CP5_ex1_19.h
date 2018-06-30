// Copyright [2018] <HankDaly>
// ex1_19.h


int foo_19()
{
    int v0,v1,v2,v3; //v0,v1 statsh istream,v2 = min,v3 = max
    std::cout<<" Enter two integersThe "<<std::endl;
    std::cin>>v0>>v1;
    if(v0>=v1)
    {
        v2 = v1;
        v3 = v0;
    }
    else
    {
        v2 = v0;
        v3 = v1;
    }
    for(int v5 = v2;v5<=v3;++v5)
    {
        std::cout<<v5<<std::endl;
    }
    return 0;
    
}