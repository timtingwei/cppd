// Copyright [2018] <HankDaly>
// ex1_13_3.h

int foo_13_3()
{
    int v0,v1; 
    std::cout<< " Enter two integersThe former is greater than the latter "<<std::endl;
    std::cin>>v0>>v1;
    for(int v2 = v1;v2<=v0;++v2)
        std::cout<<v2<<std::endl;
    return 0;
}