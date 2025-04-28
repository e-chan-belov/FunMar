#include <Abstraction.hpp>

#include <gtest.h>

TEST(Abstraction, can_create_abstraction) {
    ASSERT_NO_THROW(Abstraction abstraction);
}

TEST(Abstraction, can_is_realized_correctly) {
    AbstractionGenerator generator;
    generator.push((Variable)"x");
    generator.push((Word)"ccc");
    generator.push((Variable)"y");
    
    Abstraction abstraction = generator.generate();
    
    EXPECT_FALSE(abstraction.isRealized());
    
    
    Abstraction::Iterator iter = abstraction.begin();
    iter.realize((Word)"x");
    iter.merge();
    iter.next();
    iter.realize((Word)"y");
    iter.merge();
    
    EXPECT_TRUE(abstraction.isRealized());
}
