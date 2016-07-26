#include "preprocessor.h"
#include "global_variables.h"
#include <fstream>
#include "tinyxml2.h"
#include <sstream>
#include "initial_conditions.h"
#include "quad_bcs_plus.h"

using namespace tinyxml2;

preprocessor::preprocessor()
{
    //ctor

}

preprocessor::~preprocessor()
{
    //dtor
}

void preprocessor::initialise_program_variables(char* xmltest, global_variables &globals, domain_geometry &geometry,
                                                initial_conditions &initial_conds, quad_bcs_plus &bcs ) {

    XMLDocument xmlDoc;

    XMLError eResult = xmlDoc.LoadFile(xmltest);


    parse_global_variables(xmlDoc,  globals);
    parse_geometry_variables(xmlDoc,  geometry);
    parse_initial_conditions(xmlDoc, initial_conds);
    parse_boundary_conditions(xmlDoc, bcs);

    globals.initialise(geometry);


}

void preprocessor::parse_boundary_conditions(XMLDocument &xmlDoc, quad_bcs_plus &bcs){

    const char* parent = "boundary_conditions";



    /// WEST BCS
    bcs.w_rho = get_xml_double(parent,"west","rho",xmlDoc);
    bcs.w_u = get_xml_double(parent,"west","u",xmlDoc);
    bcs.w_v = get_xml_double(parent,"west","v",xmlDoc);
    std::string temp;

    temp = get_xml_text(parent,"west","vel_type",xmlDoc);
    if (temp.compare("dirichlet") == 0){
        bcs.w_type_vel = 1;
    }else if ( temp.compare("neumann") == 0){
        bcs.w_type_vel = 2;
    }else if ( temp.compare("periodic") == 0){
        bcs.w_type_vel = 3;
    }



    temp = get_xml_text(parent,"west","rho_type",xmlDoc);
    if (temp.compare("dirichlet") == 0){
        bcs.w_type_rho = 1;
    }else if ( temp.compare("neumann") == 0){
        bcs.w_type_rho = 2;
    }else if ( temp.compare("periodic") == 0){
        bcs.w_type_rho = 3;
    }

    /// east BCS
    bcs.e_rho = get_xml_double(parent,"east","rho",xmlDoc);
    bcs.e_u = get_xml_double(parent,"east","u",xmlDoc);
    bcs.e_v = get_xml_double(parent,"east","v",xmlDoc);


    temp = get_xml_text(parent,"east","vel_type",xmlDoc);
    if (temp.compare("dirichlet") == 0){
        bcs.e_type_vel = 1;
    }else if ( temp.compare("neumann") == 0){
        bcs.e_type_vel = 2;
    }else if ( temp.compare("periodic") == 0){
        bcs.e_type_vel = 3;
    }



    temp = get_xml_text(parent,"east","rho_type",xmlDoc);
    if (temp.compare("dirichlet") == 0){
        bcs.e_type_rho = 1;
    }else if ( temp.compare("neumann") == 0){
        bcs.e_type_rho = 2;
    }else if ( temp.compare("periodic") == 0){
        bcs.e_type_rho = 3;
    }

    /// north BCS
    bcs.n_rho = get_xml_double(parent,"north","rho",xmlDoc);
    bcs.n_u = get_xml_double(parent,"north","u",xmlDoc);
    bcs.n_v = get_xml_double(parent,"north","v",xmlDoc);


    temp = get_xml_text(parent,"north","vel_type",xmlDoc);
    if (temp.compare("dirichlet") == 0){
        bcs.n_type_vel = 1;
    }else if ( temp.compare("neumann") == 0){
        bcs.n_type_vel = 2;
    }else if ( temp.compare("periodic") == 0){
        bcs.n_type_vel = 3;
    }



    temp = get_xml_text(parent,"north","rho_type",xmlDoc);
    if (temp.compare("dirichlet") == 0){
        bcs.n_type_rho = 1;
    }else if ( temp.compare("neumann") == 0){
        bcs.n_type_rho = 2;
    }else if ( temp.compare("periodic") == 0){
        bcs.n_type_rho = 3;
    }

    /// south BCS
    bcs.s_rho = get_xml_double(parent,"south","rho",xmlDoc);
    bcs.s_u = get_xml_double(parent,"south","u",xmlDoc);
    bcs.s_v = get_xml_double(parent,"south","v",xmlDoc);


    temp = get_xml_text(parent,"south","vel_type",xmlDoc);
    if (temp.compare("dirichlet") == 0){
        bcs.s_type_vel = 1;
    }else if ( temp.compare("neumann") == 0){
        bcs.s_type_vel = 2;
    }else if ( temp.compare("periodic") == 0){
        bcs.s_type_vel = 3;
    }



    temp = get_xml_text(parent,"south","rho_type",xmlDoc);
    if (temp.compare("dirichlet") == 0){
        bcs.s_type_rho = 1;
    }else if ( temp.compare("neumann") == 0){
        bcs.s_type_rho = 2;
    }else if ( temp.compare("periodic") == 0){
        bcs.s_type_rho = 3;
    }

    // add in w velocity  afterwards for 3d
}



void preprocessor::parse_initial_conditions(XMLDocument &xmlDoc, initial_conditions &initials){

    const char* parent = "initial_conditions";
    initials.average_rho = get_xml_double(parent, "average_rho", xmlDoc);
    initials.rho_gradient.x = get_xml_double(parent,"rho","gradient","x",xmlDoc);
    initials.rho_gradient.y = get_xml_double(parent,"rho","gradient","y",xmlDoc);
    initials.rho_gradient.z = get_xml_double(parent,"rho","gradient","z",xmlDoc);
    initials.rho_origin_mag.x = get_xml_double(parent,"rho","origin_magnitude","x",xmlDoc);
    initials.rho_origin_mag.y = get_xml_double(parent,"rho","origin_magnitude","y",xmlDoc);
    initials.rho_origin_mag.z = get_xml_double(parent,"rho","origin_magnitude","z",xmlDoc);
    initials.origin_loc.x = get_xml_double(parent,"origin_location","x",xmlDoc);
    initials.origin_loc.y = get_xml_double(parent,"origin_location","y",xmlDoc);
    initials.origin_loc.z = get_xml_double(parent,"origin_location","z",xmlDoc);
    initials.velocity.x = get_xml_double(parent, "u", xmlDoc);
    initials.velocity.y = get_xml_double(parent, "v", xmlDoc);
    initials.velocity.z = get_xml_double(parent, "w", xmlDoc);

}
void preprocessor::parse_geometry_variables(XMLDocument &xmlDoc, domain_geometry &geometry){

    const char* parent = "geometry";
    geometry.X = get_xml_double(parent, "x", xmlDoc);
    geometry.Y= get_xml_double(parent, "y",xmlDoc);
    geometry.dx = get_xml_double(parent, "dx", xmlDoc);
    geometry.dy = get_xml_double(parent, "dy", xmlDoc);
    geometry.dt= get_xml_double(parent, "streaming_dt", xmlDoc);

    geometry.initialise();

}
void preprocessor::parse_global_variables(XMLDocument &xmlDoc, global_variables &globals){

    const char* parent = "global_variables";
    globals.tolerance = get_xml_double(parent, "tolerance", xmlDoc);
    globals.pre_conditioned_gamma = get_xml_double(parent, "pre_condition_gamma",xmlDoc);
    globals.simulation_length = get_xml_double(parent, "simulation_length", xmlDoc);
    globals.time_marching_step = get_xml_double(parent, "time_marching_step", xmlDoc);
    globals.reynolds_number = get_xml_double(parent, "reynolds_no", xmlDoc);
    globals.max_velocity = get_xml_double(parent, "max_velocity", xmlDoc);
    globals.simulation_name = get_xml_text(parent,"simulation_name",xmlDoc);
    globals.output_file_dir = get_xml_text(parent, "output_directory", xmlDoc);
    globals.max_mg_levels = get_xml_double(parent,"max_multi_grid_levels",xmlDoc);


}

double preprocessor::get_xml_double(const char* parent, const char* child, XMLDocument &doc){

    XMLError eResult;
    XMLNode * pRoot = doc.FirstChild();

    if (pRoot == nullptr) {

        eResult = XML_ERROR_FILE_READ_ERROR;
    }

    XMLElement * parent_element = pRoot->FirstChildElement(parent);
    if (parent_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child_element = parent_element -> FirstChildElement( child );
    if (child_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;

    double output;

    eResult = child_element->QueryDoubleText(&output);

    return output;
}
double preprocessor::get_xml_double(const char* parent, const char* child, const char* child2,
                                    const char* child3, XMLDocument &doc){

    XMLError eResult;
    XMLNode * pRoot = doc.FirstChild();

    if (pRoot == nullptr) {

        eResult = XML_ERROR_FILE_READ_ERROR;
    }

    XMLElement * parent_element = pRoot->FirstChildElement(parent);
    if (parent_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child_element = parent_element -> FirstChildElement( child );
    if (child_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child2_element = child_element -> FirstChildElement( child2 );
    if (child2_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child3_element = child2_element -> FirstChildElement( child3 );
    if (child3_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    double output;

    eResult = child3_element->QueryDoubleText(&output);

    return output;
}

double preprocessor::get_xml_double(const char* parent, const char* child, const char* child2,
                                     XMLDocument &doc){

    XMLError eResult;
    XMLNode * pRoot = doc.FirstChild();

    if (pRoot == nullptr) {

        eResult = XML_ERROR_FILE_READ_ERROR;
    }

    XMLElement * parent_element = pRoot->FirstChildElement(parent);
    if (parent_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child_element = parent_element -> FirstChildElement( child );
    if (child_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child2_element = child_element -> FirstChildElement( child2 );
    if (child2_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;

    double output;

    eResult = child2_element->QueryDoubleText(&output);

    return output;
}
const char * preprocessor::get_xml_text(const char* parent, const char* child,XMLDocument &doc){

    XMLError eResult;
    XMLNode * pRoot = doc.FirstChild();

    if (pRoot == nullptr) {

        eResult = XML_ERROR_FILE_READ_ERROR;
    }


    XMLElement * parent_element = pRoot->FirstChildElement(parent);
    if (parent_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child_element = parent_element -> FirstChildElement( child );
    if (child_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;

    const char * output;

    output = child_element->GetText();

    return output;
}
const char * preprocessor::get_xml_text(const char* parent, const char* child, const char* child2
                                        , XMLDocument &doc){

    XMLError eResult;
    XMLNode * pRoot = doc.FirstChild();

    if (pRoot == nullptr) {

        eResult = XML_ERROR_FILE_READ_ERROR;
    }


    XMLElement * parent_element = pRoot->FirstChildElement(parent);
    if (parent_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child_element = parent_element -> FirstChildElement( child );
    if (child_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;
    XMLElement* child2_element = child_element -> FirstChildElement( child2 );
    if (child2_element == nullptr) eResult =  XML_ERROR_PARSING_ELEMENT;

    const char * output;

    output = child2_element->GetText();

    return output;
}