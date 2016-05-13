#include <string>
#include <map>
#include <vector>
namespace ugf{

class Taggable{
public:
    Taggable();
    void tag(std::string tag);
    bool isTagged(std::string tag);
    std::vector<std::string> getTags();
private:
    std::vector<std::string> tags;
};

}
