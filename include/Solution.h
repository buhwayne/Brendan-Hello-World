#include "Uniform_Mesh.h"

#ifndef SOLUTION_H
#define SOLUTION_H


class Solution
{
    public:
        Solution(int _total_nodes);
        virtual ~Solution();
        double get_rho( int i) {return rho[i];};
        double get_u( int i) {return u[i];};
        double get_v( int i) {return v[i];};
        double get_w( int i) {return w[i];};

        void set_rho( int i,double arg) {rho[i] =arg;};
        void set_u( int i,double arg) {u[i] =arg;};
        void set_v( int i,double arg) {v[i] =arg;};
        void set_w( int i,double arg) {w[i] =arg;};

        void update ( double rho, double u, double v, double w , int i);
    protected:
    private:
        double *rho, *u, *v, *w;
        int total_nodes;
        void Initialise();
};

#endif // SOLUTION_H
