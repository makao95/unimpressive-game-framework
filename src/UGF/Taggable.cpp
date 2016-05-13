#include "UGF/Taggable.h"
#include <algorithm>

ugf::Taggable::Taggable(){}

void ugf::Taggable::tag(std::string tag){
    if (!isTagged(tag)){
        tags.push_back(tag);
        std::sort(tags.begin(), tags.end());
    }
}

bool ugf::Taggable::isTagged(std::string tag){
    return std::binary_search(tags.begin(), tags.end(), tag);
}

std::vector<std::string> ugf::Taggable::getTags(){
    return tags;
}

