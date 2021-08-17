#include <iostream>
#include <vector>


//СОРТИРОВКА ПОДСЧЕТОМ
//пусть диапазон чисел <=100
template<typename T>
T* count_sort(T* mass,int n, int k=100){   //n-кол-во элементов в массиве, k-диапазон чисел
    std::vector<T> temp(100,0);
    for(size_t i=0;i<n;++i){
        temp.at(mass[i])+=1;
    }
    int c=0;
for(int i=0;i<temp.size();++i){
    for(int j=0;j<temp.at(i);++j)
    {mass[c]=i;
        c++;}
}
    return mass;
}


//БЫСТРАЯ СОРТИРОВКА ХОАРА(В 2ух ФУНКЦИЯХ)
template<typename T>
T Partition(T* mass,T l,T r){
    T pivot=mass[(l+r)/2];
    T i=l;
    T j=r;
    while(i<=j){
        while(mass[i]<pivot)
            i++;
        while (mass[j]>pivot)
            j--;
        if(i<=j){
            std::swap(mass[i],mass[j]);
            if(i<r)
            i++;
            if(j>l)
            j--;
        }
    }
    return j;
}
template<typename T>
T* Quick_sort(T* mass,T l,T r){
    T mainc= Partition(mass,l,r);
    if(mainc>l+1)
        Quick_sort(mass,l,mainc);
    if(mainc<r-1)
        Quick_sort(mass,mainc+1,r);
    return mass;
            };


// СОРТИРОВКА ПУЗЫРЬКОМ
template<typename T>
T* Bubble_sort(T* mass, int n){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-1-i;++j){
            if(mass[j]>mass[j+1])
                std::swap(mass[j],mass[j+1]);

        }
    }
    return mass;
}

//СОРТИРОВКА ВСТАВКАМИ
template <typename T>
T* Insertion_sort(T* mass, int n){
    for(int i=1;i<n;++i){
        T temp=mass[i];
        int j=i-1;
        while(temp<mass[j]){
            mass[j+1]=mass[j];
            j--;
        }
       mass[j+1]=temp;
    }
    return mass;
}

//СОРТИРОВКА ВЫБОРОМ
template<typename T>
T* Selection_sort(T* mass,int n){
    for(int i=0;i<n-1;++i){
        T* min=(mass+i);
        for(int j=i+1;j<n;++j){
            if(mass[j]<mass[i])
                min=mass+j;
        }
        std::swap(mass[i],*min);
    }
    return mass;
}




int main(){
    int a[8]={1,7,9,3,6,9,2,4};
    int* b= Insertion_sort<int>(a,8);
    for(int i=0;i<8;++i)
        std::cout<<b[i]<<" ";
}