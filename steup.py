import setuptools

with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

setuptools.setup(
    name="hs-pyrender", # Replace with your own username
    version="0.1.0.dev1",
    author="Arnav Choudhary",
    author_email="contact.hot.shor.1234@gmail.com",
    description="A rndering Library made in python",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/HotShot0901/PyRender",
    packages=setuptools.find_packages(),
    license='MIT',
    keywords='render PyRender 3d',
    install_requires=['opencv-python', 'numpy'],
    classifiers=[
        'Development Status :: 3 - Alpha',
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.6',
)
