// Copyright [2018] <HankDaly>
// ex1_11.h

int foo_11()
{   int v0,v1; 
    std::cout<< " Enter two integersThe former is greater than the latter "<<std::endl;
    std::cin>>v0>>v1;
    while(v1 <= v0)
    {
        std::cout<<v1<<std::endl;
        ++v1;
    }
    return 0;
}