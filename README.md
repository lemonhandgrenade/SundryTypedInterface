# SundryTypedInterface

## Types
- [Bale](#bale)
- [Dink](#dink)
- [Dinked Bist](#dinked-bist)
- [Dloat](#dloat)
- [Flag Bearer](#flag-bearer)
- [uints](#uints)
  - [uint2_t](#uint2_t)
  - [uint4_t](#uint4_t)
  - [uint6_t](#uint6_t)
  - [uintx_t](#uintx_t)

## Bale
Bales are a type similar to std::vector.  
They have a lot of shorthand operators that can be found in the wiki.  
Example  
```cpp
sti::bale<int> bale_data = {1, 3, 4};
bale_data << 5;		// Add 5 To The Bale
if (bale_data >> 3) {	// Does Bale Data Contain 3
	bale -= 3;	// Remove A 3 From The Bale
}
```

## Dink
Dinks or **D**ata L**ink**s are data containers that hold a value and optionally another dink see ([dinked bists](#dinked-bist))  
From them you can get the hash of the object.
Example  
```cpp
sti::dink<int> dink_int = sti::dink(4);
sti::dink<float> dink_float = sti::dink(4.0f);

if (dink_int.data() == 4) {
	//...
}
std::hash dink_hash = dink_float.hash();
```

## Dinked Bist
Dinked Bists or **D**ata **B**ased L**inked** L**ist**s, are where [dinks](#dink) are best used.  
Using dinked bists you can create a sequence of data values.  
Example  
```cpp
dink<int> test_dinkc = dink(3);
dink<int> test_dinkb = dink(2, test_dinkc);
dink<int> test_dinka = dink(1, test_dinkb);

dinked_bist<int> dinked = dinked_bist<int>({test_dinka, test_dinkc, test_dinkb}); // Only The First Dink Has To Be In Order
dinked.getCurrent(); // test_dinka
dinked.next();
dinked.getCurrent(); // test_dinkb
dinked.next();
dinked.getCurrent(); // test_dinkc
```

## Dloat
Dloats or **D**ecimal F**loat**s, are a float container which keeps the set value underneath the decimal point.  
Example  
```cpp
sti::dloat value_neg = -999.9;	// -.9999
sti::dloat value_pos = 999.9;	// 0.9999

if (value_neg == -.9999) //...
if (value_pos == 0.9999) //...

```

## Flag Bearer
A Flag Bearer takes an enum and creates a container of flags from it.  
It should be noted all flags default to 0.  
Example  
```cpp
enum alphabet_enum {a,b,c,...}

sti::flag_bearer<alphabet_enum> flags = sti::flag_bearer<alphabet_enum>(z + 1);	// Set To The Count Of The Enum
flags.set_flag(b, true);		// Set The Enum Value b To True

if (flags.get_flag(b)) {		// Retrieve The Set Flag
	//...
}

```

## uints


### uint2_t
An unsigned 2 bit integer.  
Ranges from 0 -> 3.


### uint4_t
An unsigned 4 bit integer.  
Ranges from 0 -> 15.


### uint6_t
An unsigned 4 bit integer.  
Ranges from 0 -> 63.


### uintx_t
An unsigned integer of x bits.  
Ranges from 0 -> (2^x) - 1.  
Example
```cpp
sti::uintx_t value = uintx_t(5, 30);	// Create A 5 Bit Unsigned Integer With A Value Of 30
if (value == 30) {			// Can Compare To Ints
	value += 1;			// Set Value To 31
}
```