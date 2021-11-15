/*compiler figures out how much memory is needed for statically declared variables
so that when you run the program there is memory available

something as simple as 

int i = 3;

the compiler sets memory for i = 3;


Constructor initializes elements inside object


Objects can be used inside over other classes
When we create constructor, we need it to initialize the object

class Object{


};

Object::Object(){


}



clas ValidPointer{

ValidPointer (T *data);
};


class Second{
    Object inner.object;
    int x;  <- object
    ValidPointer<string> str;  <- object

};
Second::Second() : str("hey"), x(15) member initialization
here we are initializing str with hey and initializing x with 15
}

this forces us to provide the info. if we dont provide it the compiler doesn't know how to initialize it

we do this so we only have to initialize it one time.

dont use static mem allocation for valid stack element. 

in stack push() method we rely on dynamic mem allocation /// we will use the ->new<- int 
example ( = new ValidStackElement<int>(new data value we want to push one(comes from parameter from push() , point to old TOP);) //compiler figures out how much mem we need here and initializes it by calling constructor


