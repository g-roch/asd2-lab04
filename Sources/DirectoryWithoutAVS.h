//
//  DirectoryWithoutAVS.h
//  ASD2_2015
//
//  Created by Fabien Dutoit on 19.10.15.
//  Copyright © 2015 IICT, HEIG-VD. All rights reserved.
//

#ifndef DirectoryWithoutAVS_h
#define DirectoryWithoutAVS_h

#include <string>
#include <cctype>
#include <iostream>
#include <functional>

class DirectoryWithoutAVS {
private:
    std::string name;
    std::string firstname;
    std::string gender;
    std::string birthday;
    
public:
    DirectoryWithoutAVS();
    DirectoryWithoutAVS(std::string avs, /* SHOULD NOT BE USED */
                  std::string name,
                  std::string firstname,
                  std::string gender,
                  std::string birthday);
    
    std::string getName() const;
    std::string getFirstname() const;
    std::string getGender() const;
    std::string getBirthday() const;
    
    //operators
    bool operator ==(const DirectoryWithoutAVS &that) const;
    friend std::ostream& operator <<(std::ostream&, const DirectoryWithoutAVS&);
    
};

namespace std
{
    template <>
    struct hash<DirectoryWithoutAVS>
    {
        size_t operator()(const DirectoryWithoutAVS& d) const
        {
            //we use stl hash function for string type on name, we could do much better...
            /* A AMELIORER */ 
           size_t hash = 17;
           
            hash = 31*hash + std::hash<string>()(d.getName());
            hash = 31*hash + std::hash<string>()(d.getFirstname());
            hash = 31*hash + std::hash<string>()(d.getGender());
            hash = 31*hash + std::hash<string>()(d.getBirthday());
            return hash;
        }
    };
}

#endif /* DirectoryWithoutAVS_h */
