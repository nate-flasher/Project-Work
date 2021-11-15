/*
C++ references:

-Fancy name for a pointer - special pointer

-It refers to another variable

-Difference is once we make the reference it's permenant, unlike a pointer
int j=-1;
int i= nullptr;
int *p=&i;
cout <<*p;
p=&j;
we can change what p points to in this case ^^^^
This all comes with the cost of trying to remember all the characters

Reference::::

int& r = i; //this says r is a reference to an integer which in this case is i

if we want to access what is in r now we do:
cout << r; //we do this because we can never change what r points to

Here is where we tend to see references:

void swap_items(int *a, int *b){  //pointer version
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swap_items(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}


class GiantObject{
.
.
.
.
.
};

int f(GiantObject g){ //this copies GiantObject

}
int f(GiantObject& g){ //not good either

}
int f(const GiantObject& g){ //the const says that if we try to do g = ___ or g.___ then we will have a compiler error and we cant do that. So this allows us to do an effecient version. Calling this function is not expensive since your giving memory address with reference instead of copying all of it. Do this reference anytime you pass in an object(more than one value, not just an int) Here your passing int an object thats not going to be changed

}
   */
