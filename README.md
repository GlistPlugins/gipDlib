# gipDlib
This is a GlistEngine component where dlib AI library is wrapped.

For instant, dlib component works on the gipOpenCV components's video capture frame. So, the developers should link their GlistApp project to both 2 components.

- Windows developers should not forget to add
```
${workspace_loc}\..\..\..\..\glistplugins\gipDlib\libs\bin
```
directory to the GlistApp project's PATH list.
(Project->Properties->C/C++ Build->Environment->PATH)
