#ifndef DesignFilter_class_1
#define DesignFilter_class_1

class DesignFilter{
    private:
        double fc1;
        double fc2;
        double dT;
        int flag; 
        /*
        1:1LPF
        2:1HPF
        3:2LPF
        4:2HPF
        5:APD
        */
    
    public:
        double uoutk;
        double uoutk_1;
        double uoutk_2;
        double uink_1;
        double uink_2;

        DesignFilter(int N, double f, double t);
        DesignFilter(int N, double f1, double f2, double t);
        double output(double uink);
};



#endif