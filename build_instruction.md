First run "docker image ls" to make sure sonic-slave-bookworm:latest exist, if not please build via sonic-buildimage repo.

Then run:
```
docker run -it --name swss_migration_test --rm=true --privileged --cgroupns=host -v $(pwd):$(pwd) -v /lib/modules:/lib/modules -w $(pwd) -i -d sonic-slave-bookworm:latest

# get into docker
docker exec -it swss_migration_test bash

# run the script inside docker to build
./build_in_docker.sh
```

To build all targets run: `bazel build //...`. You can also target specific binaries, such as
`bazel build //orchagent:orchagent`. Or for instance, you can build p4orch unit tests with:
`bazel build //orchagent:p4orch_tests`. You could then execute the test binary directly with:
`./bazel-bin/orchagent/p4orch_tests`.

To directly execute a test target you can use `bazel test //orchagent:p4orch_tests`. Some tests
are not yet setup to execute from a bazel sandbox, so those tests might require invoking the test binary
from the correct directory. For instance, for tests under tests/mock_tests, the following is required:

```
pushd tests/mock_tests
bazel build :tests
../../bazel-bin/tests/mock_tests/tests
popd
```

To see available targets under a directory you can run a command like: `bazel query //orchagent:*`

Targets can be easily extended. If adding a new binary, use a `cc_binary` target. To include the resulting
binary in the swss debian package, add it as a dependency to the `all_binaries` target in the BUILD file at
the root of the workspace.

To add additional system dependencies, please add the dependency to the MODULE.bazel file. As much as possible,
Bazel dependencies are preferred for increased hermeticity.

You can also build a debian package using: `bazel build :swss_deb_pkg`.
A debian package containing debug symbols can be installed with `bazel build :swss_deb_dbg_pkg`.
