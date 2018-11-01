pipeline {
  agent {
    label 'SWARM-NODE-NODEJS'
  }
  stages {
    stage('build') {
     if (env.BRANCH_NAME == 'master') {
       steps {
         sh '''
           export VERSION=`npm run packageVersion | awk 'END{print}'`
           npm install
           npm run build
           npm run package
           npm run publish
           echo "version = ${VERSION}"
         '''
       }
     } else {
       sh '''
          export VERSION=`npm run packageVersion | awk 'END{print}'`
          npm install
          npm run build
          npm run dev
          echo "version = ${VERSION}"
         '''
       }
     }
    }
  }
}
