# PROJECT FOG
**By: Thomas Judge**

Project FOG is a custom-built, salted and peppered stream cipher designed for secure, discrete communication between Linux-based nodes. Unlike standard static ciphers, Project FOG utilizes a **Dynamic Seed Generation** process and a **64-bit Mersenne Twister (MT19937-64)** as a Deterministic Random Bit Generator (DRBG) to ensure every character is encrypted with a unique set of variables ($a, h, k$).

### Security Features
* **Three-Tier KDF:** Integrates a user-defined password, a 4-byte random session Salt, and a hardcoded Secret Pepper.
* **Prime Field Arithmetic:** Operates within $\mathbb{Z}_{257}$ using a primitive root (Base 3) for full ASCII coverage.
* **Resilience:** Neutralizes Rainbow Table attacks and frequency analysis through non-repeating shifts.

### Mathematical Core
Encryption follows the modular transformation:
$$result = (a \cdot 3^{x-h} + k) \pmod{257}$$
Decryption utilizes the **Extended Euclidean Algorithm** for modular inverses and a pre-computed Discrete Logarithm Table.
