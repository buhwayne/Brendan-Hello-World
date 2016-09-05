#include "quad_bcs.h"
#include "quad_bcs_plus.h"

#ifndef BOUNDARY_CONDITIONS_H
#define BOUNDARY_CONDITIONS_H


class Boundary_Conditions
{
    public:
        Boundary_Conditions(int num_x, int num_y);
        virtual ~Boundary_Conditions();
        void assign_boundary_conditions(int num_x, int num_y, quad_bcs);
        void assign_boundary_conditions(int num_x, int num_y, quad_bcs_plus _bc);
        bool get_bc( int i) {return bc[i];};

        double get_rho( int i) {return rho[i];};
        double get_u( int i) {return u[i];};
        double get_v ( int i) {return v [i];};

        int get_rho_type( int i) {return type_rho[i];};

        int get_vel_type( int i) {return type_vel[i];};

        int get_periodic_node( int i) {return periodic_node[i];};
        int get_nighbour(int i){return neighbour[i];};
    protected:
    private:

        //centroid and cell interface locations

        bool *bc;
        double * rho, * u, * v ;
        int *type_rho;
        int *type_vel;
        int *periodic_node;
        int *neighbour;
};

#endif // BOUNDARY_CONDITIONS_H
