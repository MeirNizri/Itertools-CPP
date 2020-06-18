/**
 * This class receives as input two containers or container-like, which must be the same length. 
 * The first includes objects of some kind, and the second must include Boolean objects. 
 * Returns a new container-like container that contains elements from the first container, 
 * which corresponds to them in the second container is true.
 * 
 * Author: Meir Nizri
 * Fifth assignment in cpp course
 * Date: 2020-06
 */

#pragma once

using namespace std;
namespace itertools {

    template <typename Container1, typename Container2> class compress {
        Container1 container1;
        Container2 container2;
        
    public:
        compress(Container1 c1, Container2 c2) : container1(c1), container2(c2) {}
    
        // Iterator of class compress
        class iterator{
            typename Container1::iterator itr1;  
            typename Container2::iterator itr2;

        public:
            iterator(typename Container1::iterator i1, typename Container2::iterator i2) : itr1(i1), itr2(i2) {}

            auto operator*() const {
                return *itr1;
            }
            
            iterator& operator++() {
                itr1++;
                itr2++;
			    return *this;
    		}
    		
    		const iterator operator++(int) {
    			iterator tmp = *this;
    			itr1++;
                itr2++;
			    return tmp;
    		}
            
            iterator& operator=(const iterator& it) {
                return *this;
            }

            bool operator==(const iterator& it) const {
			    return itr1 == it.itr1;
		    }

    		bool operator!=(const iterator& it) const {
			    return itr1 != it.itr1;
    		}
    	};  // END OF CLASS ITERATOR


    	iterator begin() {
    		return iterator{container1.begin(), container2.begin()};
    	}

    	iterator end() {
    		return iterator{container1.end(), container2.end()};
    	}
    }; 
}