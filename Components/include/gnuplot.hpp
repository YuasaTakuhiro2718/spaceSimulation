#ifndef gnuplot_hpp
#define gnuplot_hpp

#include <fstream>
#include <string>

class Gnuplot
{
public:
    std::string pass;
    FILE* gp;
    
    Gnuplot(std::string _pass = "/Applications/gnuplot.app/gnuplot"):pass(_pass),gp(popen(pass.c_str(),"w")){}
    
    void write_command(std::string command)
    {
        command += '\n';
        fprintf(gp,"%s", command.c_str());
    }
};

inline Gnuplot& operator<<(Gnuplot& gp,std::string command)
{
    gp.write_command(command);
    return gp;
}

#endif /* gnuplot_hpp */
