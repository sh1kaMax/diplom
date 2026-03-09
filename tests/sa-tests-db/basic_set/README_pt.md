## Тесты от Positive Technologies для открытого этапа испытаний статических анализаторов

Структура и семантика тестов повторяет предложенную [ИСП РАН](README_ispras.md). Каждый тест снабжен "шапкой" с комментарием о тестируемых в нём требованиях ГОСТ 71207-2024.

pox.xml для Java тестов:
```xml
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/maven-v4_0_0.xsd">
  <modelVersion>4.0.0</modelVersion>
  <groupId>iameter</groupId>
  <artifactId>iameter</artifactId>
  <packaging>war</packaging>
  <version>1.0-SNAPSHOT</version>
    <properties>
        <maven.compiler.source>18</maven.compiler.source>
        <maven.compiler.target>18</maven.compiler.target>
    </properties>
    <name>IAmeter Webapp</name>
  <url>https://www.ptsecurity.com</url>
  <dependencies>
	<dependency>
		<groupId>javax.servlet</groupId>
		<artifactId>javax.servlet-api</artifactId>
		<version>3.1.0</version>
		<scope>provided</scope>
	</dependency>
	<dependency>
		<groupId>commons-codec</groupId>
		<artifactId>commons-codec</artifactId>
    <version>1.15</version>
</dependency>

  </dependencies>
  <build>
      <sourceDirectory>1-tainted</sourceDirectory>
    <finalName>iameter</finalName>
      <plugins>
          <plugin>
              <groupId>org.apache.maven.plugins</groupId>
              <artifactId>maven-compiler-plugin</artifactId>
              <configuration>
                  <source>17</source>
                  <target>17</target>
              </configuration>
          </plugin>
      </plugins>
  </build>
</project>
```

packages.json для JavaScript тестов:
```javascript
{
  "name": "javascript",
  "version": "1.0.0",
  "description": "",
  "keywords": [],
  "author": "",
  "license": "",
  "dependencies": {
    "express": "^4.17.3",
    "htmlencode": "0.0.4",
    "node-htmlencode": "0.0.1"
  }
}
```