// This code is Auto-Generated. Intended to be used via l_autogen_wrapper.h
// DO NOT EDIT
        
void pendulum_step(Vector2D* q, Vector2D* dq, Vector2D* _dq, Vector2D* _ddq, float t, size_t N) {
    // Auto-generated Euler-Lagrange Equations using sympy.physics.mechanics
    // Constants have been collapsed into their values.
    float g = 0.01 /* assign proper g value here */;
    float l = 1.02 /* assign proper l value here */;
    _dq[0] = dq[0];
    _ddq[0] = -g*sin(q[0])/l;
return;
}