# JavaComponentExtractor
Разбивает программу на языке java на компоненты.
Extract components from java file.

#### Components are:
* package
* imports
* classe
* interfaces
* enums
* fields
* methods
 
#### Usage:
`JavaComponentExtractor.exe Main.java`

Main.java
```java

package com.company;

import java.lang.*;

class Main {
    public static void main(String[] args) {
        System.out.printls("Hello, world!");
    }
}
```

Output:
Main/
  Classes/
    Main/
      methods.txt
  packageNameAndImports.xml

methods.txt
```java
public static void main(String[] args) {
    System.out.printls("Hello, world!");
}
```

packageNameAndImports.xml
```xml
<program>
    <package name="com.company"/>
    <imports>
        <import importedClass="java.lang.*">
    </imports>
</program>
```

#### Not supported:
- Generics
- UTF-8 ids
- Enum classes (with methods, fields and etc)

Also there are some problem with not English comments.
If comment is located on the same line with end border of component it will produce an error in determining position of component. This is due to the fact that, as a lexical analyzer used flex, which does not support multi-byte encoding.
