#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H


class global_variables
{
    public:
        global_variables();
        virtual ~global_variables();

        const int periodic  =3;
        const int dirichlet = 1;
        const int neumann = 2;

        const double small_number = 0.00000000001;
        const double tolerance = 0.0001;

    protected:
    private:
};

#endif // GLOBAL_VARIABLES_H
