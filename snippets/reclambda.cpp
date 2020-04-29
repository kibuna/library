auto func = [&](auto &&self) { 
    return self(self);
};