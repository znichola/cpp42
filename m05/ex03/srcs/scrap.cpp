#include <string>
#include <unordered_map>
#include <functional>

class Foo {
public:
    virtual void bar() = 0;
};

class AFoo : Foo {
public:
    void bar() {
        // ...
    }

    static Foo* create() {
        return new AFoo();
    }
};

class BFoo : Foo {
public:
    void bar() {
        // ...
    }

    static Foo* create() {
        return new BFoo();
    }
};

class FooFactory {
public:
    void register(std::string typeName, std::function<unique_ptr()> ctor) {
        registeredTypes[typeName] = ctor;
    }

    Foo* create(const std::string& typeName) {
        return registeredTypes[typeName]();
    }

private:
    std::unordered_map<std::string, std::function<Foo*()>> registeredTypes;
};

int main() {
    FooFactory *factory = new FooFactory();
    factory.register("A", AFoo::Create);
    factory.register("B", BFoo::Create);

    Foo* = factory.create("A");
}
