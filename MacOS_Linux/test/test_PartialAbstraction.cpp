#include <Environment.hpp>

#include <gtest.h>

TEST(PartialAbstraction, can_create_partial_default) {
    ASSERT_NO_THROW(PartialAbstraction partial);
}

TEST(PartialAbstraction, can_create_partial) {
    InputRealization input = {1, 4};
    
    AbstractionGenerator abGenerator;
    abGenerator.push((Variable)"x");
    abGenerator.push((Word)"ccc");
    abGenerator.push((Variable)"y");
    
    FunctionAbstractionGenerator generator;
    generator.push((Word)"abc");
    generator.push((Variable)"x");
    generator.push(Function( (Variable)"f", abGenerator.generate() ));
    
    FunctionAbstraction output = generator.generate();
    
    ASSERT_NO_THROW(PartialAbstraction partial(input, output));
}

TEST(PartialAbstraction, after_create_is_not_callable) {
    InputRealization input = {1, 4};
    
    AbstractionGenerator abGenerator;
    abGenerator.push((Variable)"x");
    abGenerator.push((Word)"ccc");
    abGenerator.push((Variable)"y");
    
    FunctionAbstractionGenerator generator;
    generator.push((Word)"abc");
    generator.push((Variable)"x");
    generator.push(Function( (Variable)"f", abGenerator.generate() ));
    
    FunctionAbstraction output = generator.generate();
    
    PartialAbstraction partial(input, output);
    EXPECT_FALSE(partial.isCallable());
}

TEST(PartialAbstraction, can_dispose) {
    InputRealization input = {1, 4};
    
    AbstractionGenerator abGenerator;
    abGenerator.push((Variable)"x");
    abGenerator.push((Word)"ccc");
    abGenerator.push((Variable)"y");
    
    FunctionAbstractionGenerator generator;
    generator.push((Word)"abc");
    generator.push((Variable)"x");
    generator.push(Function( (Variable)"f", abGenerator.generate() ));
    
    FunctionAbstraction output = generator.generate();
    PartialAbstraction partial(input, output);
    
    ASSERT_NO_THROW(partial.dispose());
}

TEST(PartialAbstraction, can_dispose_correctly) { // todo before
    InputRealization input = {1, 4};
    
    AbstractionGenerator abGenerator;
    abGenerator.push((Variable)"x");
    abGenerator.push((Word)"ccc");
    abGenerator.push((Variable)"y");
    
    FunctionAbstractionGenerator generator;
    generator.push((Word)"abc");
    generator.push((Variable)"x");
    generator.push(Function( (Variable)"f", abGenerator.generate() ));
    
    FunctionAbstraction output = generator.generate();
    
    FunctionAbstraction::Iterator iterTemp = output.begin();
    iterTemp.next();
    iterTemp.realize((Word)"yyy");
    iterTemp.merge();
    
    PartialAbstraction partial(input, output);
    
    partial.moveCallFunctionIterator();
    
    partial.realizeOneFunction((Word)"yyyy");
    

    if (partial.isRealized()) {
        partial.dispose();
    }
    
    EXPECT_FALSE(partial.isActive());
}
